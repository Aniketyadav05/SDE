import React, { useEffect, useState } from 'react'
import appwriteService from "../appwrite/conf"
import { BlogCard, Button1, Container, PostCard,FadeInWrapper } from '../Components/index'
import BlurText from '../Components/Animation/BlurText';
import SplitText from '../Components/Animation/SplitText';
import Hero from "../Components/Hero.jpg"
import TiltedCard from '../Components/Animation/TitledCard';
import { FaGithub } from "react-icons/fa";
import { FaXTwitter } from "react-icons/fa6";
const Home = () => {
    const [posts, setPosts] = useState([])

    useEffect(() => {
        appwriteService.getPosts().then((posts)=>{
            if(posts){
                setPosts(posts.documents)
            }
        })
    },[])
    return (
        <div className='w-[100%] py-8 bg-[rgba(30,30,30,255)] min-h-screen'>
        <div className='flex flex-row mx-28 '>
          <div className="flex font-bold  tracking-wide mx-4" >
          <BlurText
        text="THE"
        delay={150}
        animateBy="words"
        direction="top"
        className="text-8xl mb-8 mr-6 text-gray-500 "
/>
          <BlurText
        text="DEV DEN"
        delay={250}
        animateBy="words"
        direction="top"
        className="text-8xl mb-8 text-gray-400"
/>
           
          </div>
          <p className="text-gray-400 font-extrabold mt-4 ml-4">Blog about Tech<br />Life<br />Anime.</p>
          <div className="flex space-x-4 ml-96 mt-4">
          <Button1 icon={FaGithub} link="https://instagram.com" className="shadow-gray-700 text-black"/>
      
    
          <Button1 icon={FaXTwitter} link="/dashboard" className=" shadow-gray-700 " />

          </div>
          
        </div>
        <BlogCard
        date="March 14, 2025"
        title="A Small Den for the Devs"
        readTime={1}
        description="Hello, I'm Aniket Here in this website me and some of my friends write blogs about our life, what we learnt in tech world, what type of anime is currently our favourite and many more things. if You want to join us and read our blogs you can sign up and read the blogs and can also write your own blogs❤️❤️"
        tags={["Life", "Anime", "Tech"]}
        image={Hero}
        className="w-[1250px] mb-10"
        />
{posts.length=== 0 ?(
  <div className="bg-white flex flex-row px-2 justify-between items-stretch gap-4 max-w-full">
  
  <BlogCard
    date="March 14, 2025"
    title="The Timeless Allure of Film Photography"
    readTime={8}
    description="In the digital age, where cameras are in everyone’s pocket, the resurgence of film photography might seem surprising. Yet, it has evolved from a medium of necessity to a cherished art form."
    tags={["Life", "Anime", "Tech"]}
    image={Hero}
    className="flex-1"
  />

  <div className="flex-1 flex flex-col items-center justify-center">
    <SplitText
      text="WANT TO POST BLOGS AND SEE OTHER BLOGS"
      className="text-8xl font-semibold text-center text-gray-800 "
      delay={100}
      animationFrom={{ opacity: 0, transform: "translate3d(0,50px,0)" }}
      animationTo={{ opacity: 1, transform: "translate3d(0,0,0)" }}
      easing="easeOutCubic"
      threshold={0.2}
      rootMargin="-50px"
    />
    <Button1 text="SIGN UP" link="/signup" className="w-40 h-10 mt-10 shadow-black " />

  </div>
     
</div>
) : (
<div className="bg-white flex flex-row px-2 justify-between items-stretch gap-4 max-w-full">
  
  <BlogCard
    date="March 14, 2025"
    title="The Timeless Allure of Film Photography"
    readTime={8}
    description="In the digital age, where cameras are in everyone’s pocket, the resurgence of film photography might seem surprising. Yet, it has evolved from a medium of necessity to a cherished art form."
    tags={["Life", "Anime", "Tech"]}
    image={Hero}
    className="flex-1"
  />

  <div className="flex-1 flex flex-col items-center justify-center">
    <SplitText
      text="WANT TO SEE MORE BLOGS"
      className="text-8xl font-semibold text-center text-gray-800 "
      delay={100}
      animationFrom={{ opacity: 0, transform: "translate3d(0,50px,0)" }}
      animationTo={{ opacity: 1, transform: "translate3d(0,0,0)" }}
      easing="easeOutCubic"
      threshold={0.2}
      rootMargin="-50px"
    />
    <Button1 text="See More" link="/all-posts" className="w-40 h-10 mt-10 shadow-black " />

  </div>
     
</div>
)}
<div className='py-14 bg-white  '>
              <Container>
                  <div className='flex justify-evenly gap-8 '>
                      {posts.slice(0,4).map((post) => (
                          <div key={post.$id} className=''>
                              <TiltedCard {...post}
                              />
                          </div>
                      ))}
                  </div>
              </Container>
          </div>

        </div>
  )
}

export default Home