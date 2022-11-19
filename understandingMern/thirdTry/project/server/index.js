const express = require('express')
const app = express()


app.get('/', (req, res) => {
    res.send({ hi: 'thereeeeeee' })
})

app.listen(5000)