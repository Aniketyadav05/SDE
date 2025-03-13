import React from 'react'
import { Link } from 'react-router-dom'


function Footer() {
  return (
    <footer className="bg-[rgba(30,30,30,255)] text-gray-400 py-6 px-10 mt-auto">
      <div className="flex justify-between items-center ">
        {/* Left Section */}
        <div className='flex flex-row '>
          <h1 className="text-8xl font-bold text-gray-500 tracking-wide">
            THE <span className="text-gray-400">DEV DEN</span>
          </h1>
          <p className="text-gray-400 font-extrabold mt-4 ml-4">Blog about Tech<br />Life<br />Anime.</p>
        </div>

        {/* Social Icons */}
        <div className="flex space-x-4">
          <div className="bg-orange-500 p-3 rounded-full shadow-md hover:scale-105 transition">
            <i className="fab fa-instagram text-black"></i>
          </div>
          <div className="bg-orange-500 p-3 rounded-full shadow-md hover:scale-105 transition">
            <i className="fab fa-youtube text-black"></i>
          </div>
          <div className="bg-orange-500 p-3 rounded-full shadow-md hover:scale-105 transition">
            <i className="fab fa-facebook text-black"></i>
          </div>
        </div>
      </div>

      {/* Footer Navigation */}
      <div className="border-t border-gray-700 mt-6 pt-4 flex justify-between text-sm">
        <div className="flex space-x-6">
          <Link to="/" className="hover:text-white">Terms & Conditions</Link>
          <Link to="/" className="hover:text-white">Cookie & Policy</Link>
        </div>
        <div className="flex space-x-6">
          <Link to="/" className="hover:text-white">Latest</Link>
          <Link to="/" className="hover:text-white">Trending</Link>
          <Link to="/" className="hover:text-white">Art</Link>
          <Link to="/" className="hover:text-white">Design</Link>
          <Link to="/" className="hover:text-white">Music</Link>
          <Link to="/" className="hover:text-white">Podcast</Link>
        </div>
        <p>© 2025 The Blog. All rights reserved.</p>
      </div>
    </footer>
  )
}

export default Footer