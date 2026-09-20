import { Router } from "express";

import {prisma} from "@repo/db/client"

import {RegisterSchema,LoginSchema, zodErrorMessage} from "@repo/common/common"
import bcrypt from "bcryptjs";
import { sign } from "jsonwebtoken";
import { JWT_SECRET } from "../utils";
import { auth } from "../auth.middleware";


export const authRoute = Router();


authRoute.post("/register",async(req,res)=>{

    try {
        


    const {success,data,error}=RegisterSchema.safeParse(req.body);

    if(!success){
        res.status(400).json({
            message: zodErrorMessage({error})
        })
        return
    }

    const {email, password} = data;

    const existingUser = await prisma.user.findUnique({
        where:{
            email
        }
    })

    if(existingUser){
        return res.status(409).json({
            message: "User with this email already exists"
        })
    }

    const hashedPassword = await bcrypt.hash(password,10);

    const username = email.replace(/@gmail\.com$/i, "");

    const newUser = await prisma.user.create({
      data: {
        email,
        password: hashedPassword,
        username
      }
    });
    return res.status(201).json({
      message: "User registered successfully",
      user: {
        id: newUser.id,
        email: newUser.email,
        username: newUser.username
      }
    });
        } catch (error) {
    console.error(error);

    return res.status(500).json({
      message: "Internal server error"
    });
  }

})
authRoute.post("/login", async(req,res)=>{

        try {
        
    const {success,data,error}=LoginSchema.safeParse(req.body);

    if(!success){
        res.status(400).json({
            message: zodErrorMessage({error})
        })
        return
    }

    const {email, password} = data;

    const existingUser = await prisma.user.findUnique({
        where:{
            email
        }
    })

    if(!existingUser){
        return res.status(401).json({
            message: "Invalid email or password"
        })
    }

    const isPassCorrect = await bcrypt.compare(password, existingUser.password);
    
    if(!isPassCorrect){
        return res.status(401).json({
            message: "Invalid Email or passowords"
        })
    }

    const token = sign({userId : existingUser.id}, JWT_SECRET)
    
  return res.status(200).json({
      message: "Logged in successfully",
      user: {
        token,
        id: existingUser.id,
        email: existingUser.email,
        username: existingUser.username
      }
    });
        } catch (error) {
    console.error(error);

    return res.status(500).json({
      message: "Internal server error"
    });
  }

})

authRoute.get("/me", auth, async(req,res)=>{

    const userId = req.userId;

    const user = await prisma.user.findUnique({
        where:{
            id: userId
        },
        omit:{
            password: true
        },
        include:{
            rating: true,
            gameMembers: {
                include: {
                    game: true
                }
            }
        }
    })

    return res.json({
        message:"User fetched Successfully",
        user
    })
})