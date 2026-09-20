import express from "express";
import { authRoute } from "./routes/auth.routes";


const app = express();

app.use(express.json());

app.use("/api/v1/auth", authRoute)

app.listen(4000,()=>{
    console.log("Server is running at PORT:", 4000);
})