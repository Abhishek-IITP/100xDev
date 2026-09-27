import express from "express";
import "dotenv/config"
import { PrismaPg } from "@prisma/adapter-pg";
import { PrismaClient } from "./generated/prisma/client";

const app = express();

app.use(express.json());

const prisma = new PrismaClient({
  adapter: new PrismaPg({ connectionString: process.env.DATABASE_URL }),
})

const PORT = 3000;


app.listen(PORT,()=>{
    console.log("Server is running at PORT: ",PORT);
});

app.get("/user/:id",async(req, res)=>{

    try {
        
   
    const {id} = req.params ;

    const getUser= await prisma.user.findFirst({
        where:{
            id,
        },omit:{
            password: true
        }, include:{
            todo:{
                omit:{
                    userId: true
                }
            }
        }
    })

    if(!getUser){
        return res.status(404).json({
            message: "NO User found."
        })
    }

    return res.status(200).json({
        data: getUser
    })

     } catch (error) {
         console.error("Database error:", error);
        return res.status(500).json({ message: "Internal server error" });
    }
    
})
app.get("/users",async(req, res)=>{

    try {
    const getUser= await prisma.user.findMany()

    if(!getUser){
        return res.status(404).json({
            message: "NO User found."
        })
    }

    return res.status(200).json({
        data: getUser
    })

     } catch (error) {
         console.error("Database error:", error);
        return res.status(500).json({ message: "Internal server error" });
    }
    
})








export const  createUser=async()=> {
    try {
        const newUser = await prisma.user.create({
            data:{
                username: "abhi9",
                password: "123",
                age: 21,
                city: "Jamshedpur"
            }
        })
        return newUser;
    } catch (error) {
        console.error("Failed to create user:", error);
    throw error;
    }
}

export const findUser=async()=>{

    const getUser = await prisma.user.findFirst({
        where:{
            id: "77b46cad-55e2-45e1-b4c5-fccd91699245"
        },
        omit: {
        password: true
    },include:{
            todo:true
        }
    })

    if(!getUser){
        console.log("No user with this id exists");
        return;
    }

    console.log(getUser);
}
