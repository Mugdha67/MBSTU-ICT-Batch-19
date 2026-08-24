let count = 0;  
let spiritualGoals = 0;  
function increase(){ 
  if (count < 108) {
    count++;   
    updateCounter();
  }
  if (count === 108) {
    completeGoal();
  }
} 
function decrease() {  
  if (count > 0) {
    count--;   
    updateCounter();  
  }
}   
function reset() {   
  count = 0;   
  updateCounter();  
}  
function completeGoal() {
  spiritualGoals++;
  document.getElementById("spiritual-goal").innerText = spiritualGoals;
  count = 0;
  updateCounter();
  
  // Visual feedback for completing a goal
  const counterBox = document.querySelector(".counter-box");
  counterBox.classList.add("goal-achieved");
  setTimeout(() => {
    counterBox.classList.remove("goal-achieved");
  }, 1000);
}
function updateCounter() {   
  document.getElementById("counter").innerText = count;  
} 