
const url='https://emailreputation.abstractapi.com/v1/';
const api_key='a64f2ab1d01e49b0b64ee78ad84beeef';
const email='mugdha.saha67@gmail.com';

fetch(`${url}?api_key=${api_key}&email=${email}`)
  .then(response => response.json())
  .then(data => {
    if(data.email_deliverability.status==='deliverable'){
      console.log("The email address is valid and deliverable.");
    }    else{
      console.log("The email address is not deliverable.");
    }
  })