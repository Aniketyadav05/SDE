import React from 'react'
import { useDispatch } from 'react-redux'
import authService from '../../appwrite/auth'
import { logout } from '../../Store/authSlice'
const LogoutBtn = () => {
  const dispatch = useDispatch();
  const logoutHandler = () =>{
    authService.logout().then(() =>{
      dispatch(logout())
    })
  }
  return (
    <button className='inline-block px-6 py-2 bg-[#eb7160] duration-200 hover:bg-[#b96a67fd] rounded-full'>Logout</button>
  )
}

export default LogoutBtn