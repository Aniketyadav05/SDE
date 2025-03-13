import React, { useEffect, useState } from 'react'
import appwriteService from "../appwrite/conf"
import { Container,PostCard} from '../Components/index'
import TiltedCard from '../Components/Animation/TitledCard'
const AllPosts = () => {
    const [posts, setPosts] = useState([])
    useEffect(() => {

    },[])
    appwriteService.getPosts([]).then((Posts) => {
        if(posts){
            setPosts(Posts.documents)
        }
    })
  return (
    <div className='w-full py-8 bg-white'>
        <Container>
            <div className='flex flex-wrap gap-10'>
                {posts.map((post) => (
                    <div key={post.$id} className='m-4'>
                        <TiltedCard {...post}
                        />
                    </div>
                ))}
            </div>
        </Container>
    </div>
  )
}

export default AllPosts