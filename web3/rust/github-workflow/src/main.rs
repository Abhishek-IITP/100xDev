// use std::{collections::HashMap};

// use serde::{Deserialize, Serialize};


// #[derive(Debug,Serialize,Deserialize)]

// struct Workflow{
//     name: String,
// #[serde(rename = "on")]
//     on: Trigger,

//     jobs: HashMap<String,Job>,
// }

// #[derive(Debug,Serialize,Deserialize)]

// struct  Trigger{
//     push: Option<PushTrigger>,
//     pull_request: Option<PushTrigger>,
// }

// #[derive(Debug,Serialize,Deserialize)]

// struct  PushTrigger{
//     branches: Option<Vec<String>>
// }

// #[derive(Debug,Serialize,Deserialize)]

// struct  Job{

//     #[serde(rename="runs-on")]
//     runs_on: String,
//     steps: Vec<Step>
// }

// #[derive(Debug, Serialize, Deserialize)]

// struct  Step{
//     name: String,

//     #[serde(skip_serializing_if  = "Option::is_none")]
//     uses: Option<String>,


//     #[serde(skip_serializing_if  = "Option::is_none")]
//     run: Option<String>,
    
//     #[serde(skip_serializing_if  = "Option::is_none", rename = "working-directory")]
//     working_directory: Option<String>
// }



// fn main(){
//     let workflow = Workflow{
//         name: String::from("build-and-lint"),

//         on: Trigger { 
//             push: Some(PushTrigger{
//                 branches: Some(vec![String::from("main"),String::from("dev")])
//             }
//         ), pull_request: Some(PushTrigger{
//                  branches: Some(vec![String::from("main"), String::from("dev")])
//                  }
//             )
//         },

//         jobs: HashMap::from([
//             (
//                 String::from("build-and-lint"),

//                 Job{
//                     runs_on: String::from("ubuntu-latest"),

//                     steps: vec![
//                         Step{
//                             name: String::from("Checkout repo"),
//                             uses: Some(String::from("actions/checkout@v3")),
//                             run: None,
//                             working_directory: None

//                         },
//                         Step{
//                             name: String::from("Setup Node"),
//                             uses: Some(String::from("actions/setup-node@v3")),
//                             run: None,
//                             working_directory: None

//                         },
//                         Step{
//                             name: String::from("Install backend dependencies"),
//                             uses: None,
//                             working_directory: Some(String::from("server")),
//                             run: Some(String::from("npm ci")),

//                         },
//                         Step{
//                             name: String::from("Lint backend"),
//                             uses: None,
//                             run: Some(String::from("npm run lint -- --max-warnings=0")),
//                             working_directory: Some(String::from("server"))

//                         },
//                         Step{
//                             name: String::from("Install frontend dependencies"),
//                             uses: None,
//                             run: Some(String::from("npm ci")),
//                             working_directory: Some(String::from("client"))

//                         },
//                         Step{
//                             name: String::from("Lint frontend"),
//                             uses: None,
//                             run: Some(String::from("npm run lint -- --max-warnings=0")),
//                             working_directory: Some(String::from("client"))

//                         },
//                         Step{
//                             name: String::from("Build backend image"),
//                             uses: None,
//                             run: Some(String::from("docker build -t backend ./server")),
//                             working_directory: None

//                         },
//                         Step{
//                             name: String::from("Build frontend image"),
//                             uses: None,
//                             run: Some(String::from("docker build -t frontend ./client")),
//                             working_directory: None

//                         },
//                     ]
//                 }
//             )
//         ])

//     };

//     let yaml = serde_yaml::to_string(&workflow).unwrap();
//     println!("{}", yaml);
// }

use serde::{Deserialize, Serialize};


#[derive(Deserialize,Serialize)]
struct SignupResponse{
    message : String
}
fn main(){
    let s = SignupResponse{
        message: String::from("Hello world")
    };

    let json_str = serde_json::to_string(&s).unwrap();

    println!("{}", json_str);


}