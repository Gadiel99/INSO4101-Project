const express = require('express');
const passport = require('passport');
const GoogleStrategy = require('passport-google-oauth20').Strategy
const keys = require('./config/keys.js')

const app = express()

passport.use(new GoogleStrategy({
    clientID: keys.googleClientID,
    clientSecret: keys.googleClientSecret,
    callbackURL: '/auth/google/callback',
    proxy: true
},
    async (accessToken, refreshToken, profile, done) => {

        // const existingUser = await User.findOne({ googleId: profile.id })

        // if (existingUser) {
        //     return done(null, existingUser)
        // }
        // const user = await new User({ googleId: profile.id }).save()
        // done(null, user)

    })
);

app.get('/auth/google', passport.authenticate('google', {
    scope: ['profile', 'email']
}));

app.get('/auth/google/callback', passport.authenticate('google'))


app.get('api/logout', (req, res) => {
    req.logout()
    res.send(req.user)
})

app.get('/api/current_user', (req, res) => {
    res.send(req.user)
})


const PORT = process.env.PORT || 5000
app.listen(PORT)