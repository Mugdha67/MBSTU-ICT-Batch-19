var xhttp = new XMLHttpRequest(); 
  xhttp.open("GET", "info.json", true); 
  xhttp.onreadystatechange = function () { 
    if (this.readyState == 4 && this.status == 200) { 
      var response = JSON.parse(this.responseText); 
      console.log(response.blog.name);  
    } 
  }; 
  xhttp.send(); 