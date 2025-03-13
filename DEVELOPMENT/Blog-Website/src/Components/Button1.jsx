import React from "react";
import { Link } from "react-router-dom";

const Button = ({ icon, text, link, className }) => {
  return (
    <Link
      to={link}
      className={`bg-orange-500 h-10 w-10 flex items-center justify-center rounded-full shadow-md font-extrabold hover:scale-105 transition ${className}`}
    >
      {icon ? <i className={`${icon} text-black`}></i> : <span className="text-black">{text}</span>}
    </Link>
  );
};

export default Button;
