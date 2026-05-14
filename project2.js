const techStack = [
  { id: 1, tech: "Javascript", version: 7 },
  { id: 2, tech: "NodeJS", version: 24 },
  { id: 3, tech: "ReactJS", version: 18 },
];

for(let i=0; i<techStack.length; i++){
    console.log(techStack[i]);
}

for(let tech of techStack){
    console.log(tech);
}

const tech1 = techStack.forEach((item, index) => {
    console.log(item);
    if (index === 2) {
      console.log(item);
    }
  if (item.tech1 === "ReactJS") {
    console.log(item);
  }
});

const text = document.getElementById("text")

const tech2 = techStack.map((item) => {
  text.innerHTML += `${item.tech2}`+ "<br/>" 
});