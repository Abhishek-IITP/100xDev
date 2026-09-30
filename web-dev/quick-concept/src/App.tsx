import { useEffect, useState } from "react";

// setInterval itself doesn't make React update. It only repeatedly executes a function. useState is what tells React that the UI needs to update.

interface PostProps {
  name: string,
  description: string
}
export function App() {


const [posts, setPosts] = useState([
  {
    name: "Abhishek",
    description: "Go to gym"
  },
  {
    name: "Akay",
    description: "Start recursion"
  }
]);

useEffect(() => {
  const interval = setInterval(() => {
    setPosts(prev => [
      ...prev,
      {
        name: "Hacker hi kahde",
        description: "Lag gye tere lawde"
      }
    ]);
  }, 1000);

  return () => clearInterval(interval);
}, []);

 return <div className="min-h-screen bg-slate-100 p-6">

   <main className="mx-auto max-w-2xl rounded-lg border border-slate-300 bg-white p-6 shadow-sm">
   <h1 className="mb-6 border-b border-slate-200 pb-4 text-3xl font-bold text-slate-900">
      LinkedIn!!!
    </h1>
   <div className="space-y-4">
   {posts.map(p =><Post key={p.name} name = {p.name} description={p.description} />)}
   </div>
   </main>
 </div>
}


function Post(props : PostProps){
  return <article className="rounded-md border border-slate-200 bg-slate-50 p-4">

    <h2 className="mb-2 text-xl font-semibold text-slate-800">
      {props.name}
    </h2>
    <p className="text-slate-600">
        {props.description}
    </p>
  </article>
}
export default App;
