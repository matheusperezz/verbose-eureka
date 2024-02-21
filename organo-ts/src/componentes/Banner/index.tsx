import './Banner.css'
import React from 'react'

interface BannerProps {
    srcImage: string
    alt?: string
}

export const Banner = ({ srcImage, alt }: BannerProps) => {
    // JSX <img src="/imagens/banner.png" alt="O banner principal da página do Organo"/>
    return (
        <header className="banner">
            <img src={ srcImage } alt={ alt }/>
        </header>
    )
}

export default Banner