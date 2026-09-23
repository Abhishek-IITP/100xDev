use borsh::{BorshDeserialize, BorshSerialize};
use solana_program::entrypoint::{entrypoint, ProgramResult};
use solana_program::program_error::ProgramError;
use solana_program::{ pubkey::Pubkey};
use solana_program::account_info::{AccountInfo, next_account_info};


entrypoint!(process_instruction)

#[derive(BorshSerialize,BorshDeserialize,Debug)]
struct Counter {
    count : u32,
    authority: Pubkey
}
#[derive(BorshSerialize, BorshDeserialize, Debug)]
enum  InstructionData{
    Increase,
    Decrease,
    Init,
}

pub fn process_instruction(
    _pubkey: Pubkey,  //the public key of where this program is deployed.
    accounts: &[AccountInfo], //Array of all the accounts you are going to read from or write in this transaction , FOR this contract this arrayw should do, read from counter account[Counter Account] 
    instruction_data: &[u8] //inc or dec [0] , [1]
)-> ProgramResult{

    // check if the counter account has signed the txn or not
    let mut iter = accounts.iter();

    let counter_account = next_account_info(&mut iter)?;

    let user_account = next_account_info(&mut iter)?;

    if !user_account.is_signer{
          return Err(solana_program::program_error::ProgramError::MissingRequiredSignature);
    }
    
    //read the data inside the counter account, deserialize it to a struct

    let instruction = InstructionData::try_from_slice(instruction_data)
    .map_err(|_| ProgramError::InvalidInstructionData)?;

    // Inc the val / dec the value based on whatever the user want to do

    match instruction {


        InstructionData::Init=> {

            if !counter_account.is_signer{
                return Err(ProgramError::MissingRequiredSignature);
            }
                let counter = Counter{
                    count:0,
                    authority: *user_account.key,
                };
                counter.serialize(
                &mut *counter_account.data.borrow_mut()
            )?;
            
        },
        InstructionData::Increase => {
            let mut counter = Counter::try_from_slice(&counter_account.data.borrow())?;

            if counter.authority != *user_account.key{
                return Err(ProgramError::InvalidArgument);
            }
            counter.count += 1;

           counter.serialize(&mut *counter_account.data.borrow_mut())?;
        }

        InstructionData::Decrease=> {

            let mut counter = Counter::try_from_slice(&counter_account.data.borrow())?;

            if counter.authority != *user_account.key {
                return Err(ProgramError::InvalidArgument);
            }

            if counter.count > 0 {
            counter.count -= 1;
        }
        counter.serialize(&mut *counter_account.data.borrow_mut())?;
        },
    }

    

Ok(())
}