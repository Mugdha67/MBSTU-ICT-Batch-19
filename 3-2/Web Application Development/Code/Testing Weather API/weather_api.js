const url = 'https://api.openweathermap.org/data/2.5/weather';
const apiKey = '81e3ff69832a4003843143111261601';   // replace with your key
const city = 'Dhaka';

fetch(`${url}?q=${city}&appid=${apiKey}&units=metric`)
  .then(response => response.json())
  .then(data => {
    if (data.cod === 200) {
      console.log('Weather API is working ✅');
      console.log('City:', data.name);
      console.log('Temperature:', data.main.temp + '°C');
      console.log('Condition:', data.weather[0].description);
      
      // full JSON output
      console.log('Full JSON:', data);
    } else {
      console.log('Weather API error ❌');
      console.log(data.message);
    }
  })
  .catch(error => {
    console.error('Fetch error:', error);
  });