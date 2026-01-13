function loadStudents(dept) { 
if (dept === "") { 
document.getElementById("output").innerHTML = ""; 
return; 
} 
var xhr = new XMLHttpRequest(); 
xhr.open("GET", "info.json", true); 
xhr.onreadystatechange = function () { 
if (xhr.readyState === 4 && xhr.status === 200) { 
var students = JSON.parse(xhr.responseText); 
var html = "<ul>"; 
for (var i = 0; i < students.length; i++) { 
if (students[i].dept === dept) { 
html += "<li>" + students[i].name + "</li>"; 
} 
} 
html += "</ul>"; 
document.getElementById("output").innerHTML = html; 
} 
}; 
xhr.send(); 
}