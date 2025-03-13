import React, { useEffect, useState } from 'react'
import appwriteService from "../appwrite/conf"
import { BlogCard, Button1, Container, PostCard,FadeInWrapper } from '../Components/index'
import BlurText from '../Components/Animation/BlurText';
import SplitText from '../Components/Animation/SplitText';
import Hero from "../Components/Hero.jpg"
import TiltedCard from '../Components/Animation/TitledCard';
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
        delay={250}
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
          <div className="flex space-x-4 ml-40">
          <Button1 icon="fab fa-instagram" link="https://instagram.com" />
          <Button1 text="Go" link="/dashboard" className="w-16 h-10 shadow-[rgb(118,117,121)] " />

          </div>
          
        </div>
        <BlogCard
        date="March 14, 2025"
        title="The Timeless Allure of Film Photography"
        readTime={8}
        description="In the digital age, where cameras are in everyone’s pocket, the resurgence of film photography might seem surprising. Yet, it has evolved from a medium of necessity to a cherished art form."
        tags={["Trends", "Photography", "Film"]}
        image={Hero}
        className="w-[1250px] mb-10"
        />
<div className="bg-white flex flex-row px-2 justify-between items-stretch gap-4 max-w-full">
  
  <BlogCard
    date="March 14, 2025"
    title="The Timeless Allure of Film Photography"
    readTime={8}
    description="In the digital age, where cameras are in everyone’s pocket, the resurgence of film photography might seem surprising. Yet, it has evolved from a medium of necessity to a cherished art form."
    tags={["Trends", "Photography", "Film"]}
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
<div className='py-8 bg-white '>
              <Container>
                  <div className='flex flex-row justify-between items-stretch gap-4 max-w-full '>
                      {posts.slice(0,3).map((post) => (
                          <div key={post.$id} className='m-4'>
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