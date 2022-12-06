//setup a express server that accepts a post request and prints the body
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
app.use(bodyParser.json());
app.post('/', function(req, res) {
    console.log(req.body);
    res.send('ok');
})

app.listen(3000, function() {
    console.log('Listening on port 3000');
});