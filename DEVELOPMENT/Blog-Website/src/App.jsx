import React, { useState, useEffect } from 'react'
import {useDispatch} from 'react-redux'
import authService from './appwrite/auth'
import {login, logout} from './Store/authSlice'
import {Header,Footer} from './Components/index'
import { Outlet } from 'react-router-dom'
import FadeInWrapper from './Components/Animation/FadeInWrapper'
const App = () => {
  const [Loading,setLoading] = useState(true);
  const dispatch = useDispatch()
  
  useEffect(() => {
    authService.getCurrentUser()
    .then((userData) =>{
      if(userData){
        dispatch(login({userData}))
      }
      else{
        dispatch(logout())
      }
    })
    .finally(() => setLoading(false))
  }, [])
  
  return !Loading ? (
    <FadeInWrapper>
      <div className='min-h-screen flex flex-col  bg-[rgba(30,30,30,255)]'>
        <div className="flex flex-col min-h-screen" >
          <Header/>
          <main className='w-full  flex-grow'>
          <Outlet />
          </main>
          <Footer/>
        </div>
      </div>
      </FadeInWrapper>
  ) : /* From Uiverse.io by SmookyDev */ 
  <div
    className="w-32 aspect-square rounded-full relative flex justify-center items-center animate-[spin_3s_linear_infinite] z-40 bg-[conic-gradient(white_0deg,white_300deg,transparent_270deg,transparent_360deg)] before:animate-[spin_2s_linear_infinite] before:absolute before:w-[60%] before:aspect-square before:rounded-full before:z-[80] before:bg-[conic-gradient(white_0deg,white_270deg,transparent_180deg,transparent_360deg)] after:absolute after:w-3/4 after:aspect-square after:rounded-full after:z-[60] after:animate-[spin_3s_linear_infinite] after:bg-[conic-gradient(#065f46_0deg,#065f46_180deg,transparent_180deg,transparent_360deg)]"
  >
    <span
      className="absolute w-[85%] aspect-square rounded-full z-[60] animate-[spin_5s_linear_infinite] bg-[conic-gradient(#34d399_0deg,#34d399_180deg,transparent_180deg,transparent_360deg)]"
    >
    </span>
  </div>
  
}

export default App