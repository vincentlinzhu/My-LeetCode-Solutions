import React from 'react';
import { useState } from 'react';
import './App.css';

function App() {
  const [idx, setIdx] = useState(0);
  
  const images = [
    "https://tesla-cdn.thron.com/delivery/public/thumbnail/tesla/9c6b5f01-494b-4764-9d64-364ff3749711/bvlatuR/std/600x502/models_02?lcid=2b084dd2-ade1-49ec-a470-45363112146c&v=52&dpr=200",
    "https://tesla-view.thron.com/api/xcontents/resources/delivery/getThumbnail/tesla/600x502/35ecbb56-a20e-4ebe-8cc6-84a2fc34413e.jpg?v=25&dpr=200",
    "https://tesla-cdn.thron.com/delivery/public/thumbnail/tesla/2d815c9e-2f42-4fdd-b312-1949b80810f7/bvlatuR/std/600x502/Roadster_01?lcid=aed08877-ce08-416f-a384-e57e8449ead7&v=12&dpr=200",
  ];

  const shiftImgPrev = () => {
    if (idx === 0) {
      setIdx(images.length() - 1);
    } else {    
      setIdx(idx - 1);
    }  
  }
  
  const shiftImgNext = () => {
    if (idx === images.length() - 1) {
      setIdx(0);
    } else { 
      setIdx(idx + 1);
    }
  }
  
  return (
    <div>      
      Hello World
      <img src={images[idx]} alt="Tesla Product"/>
      <button onClick={shiftImgPrev}>Prev</button>
      <button onClick={shiftImgNext}>Next</button>
    </div>
  );
}

export default App