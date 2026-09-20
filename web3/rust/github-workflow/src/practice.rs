use std::collections::HashMap;

use serde::{Deserialize, Serialize};



#[derive(Debug, Serialize, Deserialize)]
struct  WorkFlow{
    name: String,

    #[serde(rename = "on")]
    on: Trigger,

    jobs: HashMap<String,Job>
}

#[derive(Debug,Serialize,Deserialize)]
struct  Trigger{
    push: Option<PushTrigger>
}


#[derive(Debug,Serialize,Deserialize)]
struct  PushTrigger{
    branches: Option<Vec<String>>
}



#[derive(Debug, Serialize, Deserialize)]
struct Job{
    #[serde(rename = "runs-on")]
    runs_on: String,
    steps: Vec<Step>,
}


#[derive(Debug, Serialize, Deserialize)]

struct  Step{
    name: String,

    #[serde(skip_serializing_if  = "Option::is_none")]
    uses: Option<String>,


    #[serde(skip_serializing_if  = "Option::is_none")]
    run: Option<String>,
}

fn main(){
    let workflow= WorkFlow{
        name: String::from("Rust CI"),

        on: Trigger { 
            push: Some(PushTrigger {
                 branches: Some(vec![
                    String::from("main")

            ]),
        }),
         },

         jobs: HashMap::from([
            (
                String::from("build"),

                Job{
                    runs_on: String::from("ubuntu-latest"),

                    steps: vec![
                        Step{
                            name: String::from("checkout"),
                            run: None,
                            uses: Some(
                                String::from("actions/checkout@v4")
                            ),
                        },

                        Step{
                            name: String::from("Run tests"),
                            run: Some(
                                String::from("cargo test")
                            ),
                            uses: None,
                        }
                    ]
                }
            )
         ])
    };
    let yaml = serde_yaml::to_string(&workflow).unwrap();

    println!("{}", yaml);

}