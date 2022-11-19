
const express = require('express')
const passport = require('passport')
const GoogleStrategy = require('passport-google-oath20')
const app = express();

passport.use(new GoogleStrategy());



app.get(
    '/auth/google',
    passport.authenticate('google', {
        scope: ['profile', 'email']
    })
)

app.get('/auth/google/callback', passport.authenticate('google'));

const PORT = process.env.PORT || 5000;
app.listen(PORT);