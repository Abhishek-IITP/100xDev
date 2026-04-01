import { useEffect, useState } from "react";
import React, { useMemo } from "react";
import {
  ConnectionProvider,
  useConnection,
  useWallet,
  WalletProvider,
} from "@solana/wallet-adapter-react";
import { WalletAdapterNetwork } from "@solana/wallet-adapter-base";
import { UnsafeBurnerWalletAdapter } from "@solana/wallet-adapter-wallets";
import {
  WalletModalProvider,
  WalletDisconnectButton,
  WalletMultiButton,
} from "@solana/wallet-adapter-react-ui";
import { clusterApiUrl, Connection, LAMPORTS_PER_SOL, PublicKey, SystemProgram, Transaction } from "@solana/web3.js";

// Default styles that can be overridden by your app
import "@solana/wallet-adapter-react-ui/styles.css";
export function App() {
  const endpoint =clusterApiUrl("devnet");
  return (
    <ConnectionProvider endpoint={endpoint}>
      <WalletProvider wallets={[]} autoConnect>
        <WalletModalProvider>
          <Topbar />
          <Portfolio/>
          <Transactions/>
        </WalletModalProvider>
      </WalletProvider>
    </ConnectionProvider>
  );
}

function Topbar() {

  const {publicKey} = useWallet()
  return (
    <div style={{ display: "flex", justifyContent: "flex-end", gap: "15px" }}>
      {!publicKey && <WalletMultiButton />}
      {publicKey && <WalletDisconnectButton />}
    </div>
  );
}

function Portfolio(){
  const {publicKey} = useWallet();

  const  {connection } = useConnection();
  const [balance,setBalance] = useState<null | number>(null);

  useEffect(()=>{
    if(publicKey){
      connection.getBalance(publicKey)
      .then(balance=>setBalance(balance/LAMPORTS_PER_SOL))
    }
  },[publicKey,connection])

  const shortenText = (str: string) => {
    if (str.length <= 10) return str;
    return str.slice(0, 5) + "..." + str.slice(-5);
  };
   const displayText = publicKey
    ? shortenText(publicKey.toString())
    : "Not connected";
  return <div>
      <p>Address - {displayText}</p>
      <p>The Balance is {publicKey? balance: ""}</p>
    </div>
}

function Transactions(){
  const { publicKey, sendTransaction } = useWallet();

  const {connection} = useConnection();

  const [reciver, setReciver] = useState("");
  const [amount, setAmount] = useState("");
  const [loading, setLoading] = useState(false);

  async function handleSend(){

    if(!publicKey){
      alert("conncet your wallet first");
      return;
    }
      if (!reciver || !amount) {
    alert("Enter receiver and amount");
    return;
  }

    try {
      setLoading(true);
      const transaction = new Transaction().add(
      SystemProgram.transfer({
        fromPubkey: publicKey,
        toPubkey: new PublicKey(reciver),
        lamports: Number(amount)* LAMPORTS_PER_SOL,
      })
    )
    const signature = await sendTransaction(transaction,connection);
    await connection.confirmTransaction(signature,"confirmed");
    console.log("Success:", signature);
    alert("Transaction successful 🚀");
    } catch (error) {
      if(error){
        console.log("transation section se error aaya h bhai", error);
      }
    }  finally {
    setLoading(false); 
  }
  }


  return <div>
    <input type="text" placeholder="Reciver Public Key" value={reciver} onChange={(e)=>setReciver(e.target.value)}/>
    <input type="text" placeholder="Amount (sol)" value={amount} onChange={(e)=> setAmount(e.target.value)} />
    <button onClick={handleSend} disabled={loading}>{loading ? "Sending..." : "Send"}</button>
  </div>
}

export default App;
