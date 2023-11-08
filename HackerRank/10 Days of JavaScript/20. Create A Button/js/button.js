//  Creating a button element using js
var btn = document.createElement("Button");
//  Initializing the button innerHTML with 0 and assigning a class and id to it for CSS
btn.innerHTML = "0";
btn.id = "btn";
btn.className = "btnClass";
//  Appending the child to the HTML
document.body.appendChild(btn);
//  Adding a function for increasing the numbers
btn.onclick = function() {
    btn.innerHTML++;
}
