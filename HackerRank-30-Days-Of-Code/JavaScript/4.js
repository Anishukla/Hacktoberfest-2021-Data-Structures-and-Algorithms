function Person(initialAge){
    if(initialAge<0){
        console.log("Age is not valid, setting age to 0.");
    }
    // Add some more code to run some checks on initialAge
  this.amIOld=function(){
   if(initialAge<13){
        console.log("You are young.");
    }else if(initialAge>=13 && initialAge<18){
        console.log("You are a teenager.");
    }else{
        console.log("You are old.");
    }
  };
   this.yearPasses=function(){
         initialAge+=1;
   };
}