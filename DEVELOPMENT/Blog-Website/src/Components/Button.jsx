import React from 'react'

const Button = ({
    children,
    type = 'button',
    bgColor = '#eb7160',
    textColor = "black",
    className = '',
    ...props
}) => {
  return (
    <button 
        className={`px-4 py-2 ${className} ${bgColor} ${textColor}`} {...props}>
        {children}
    </button>    
)
}

export default Button