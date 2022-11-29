//component imports
import HomePage from './/views/HomePage';
import UprmHomePage from './/views/UprmHomePage';
import Login from './/views/Login';
import About from './/views/About'
import Account from './/views/Account';
import AccountSettings from './/views/AccountSettings';
import Notifications from './/views/Notifications';
import MeetsScheduled from './/views/MeetsScheduled';
import MeetsPending from './/views/MeetsPending';
import PairUp from './/views/PairUp';
import TimeSlots from './/views/TimeSlots';
import Match from './/views/Match';
import EditMeets from './/views/EditMeets';
import ThisMeet from './/views/ThisMeet';
import MeetStarted from './/views/MeetStarted';
import EndOfMeetSurvey from './/views/EndOfMeetSurvey';
import ErrorPage from './/views/ErrorPage';



//css imports
import './App.css';
import './viewsCss.css';

//state use import
import { useState } from 'react';

//react import

import React, { Component } from 'react'

//routers import
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom'

import { connect } from 'react-redux'
import * as actions from './actions'


class App extends Component {

  componentDidMount() {
    this.props.fetchUser()

  }

  render() {
    return (
      <Router>
        <div id='mainDiv'>


          <p id='legacy'> {'< background meets , uprm chapter >'}</p>
          <div id="topLine" className='thoseTwoLines'></div>
          <a href="http://localhost:5000/auth/google"> Sign in with google</a>

          <Routes>
            <Route path='/' element={<HomePage />} />
            <Route path='/Login' element={<Login />} />
            <Route path='/UprmHomePage' element={<UprmHomePage />} />
            <Route path='/UprmHomePage/Account' element={<Account />} />
            <Route path='/UprmHomePage/Account/AccountSettings' element={<AccountSettings />} />
            <Route path='/UprmHomePage/About' element={<About />} />
            <Route path='/UprmHomePage/PairUp' element={<PairUp />} />
            <Route path='/UprmHomePage/PairUp/TimeSlots' element={<TimeSlots />} />
            <Route path='/UprmHomePage/PairUp/Match' element={<Match />} />
            <Route path='/UprmHomePage/PairUp/EditMeets' element={<EditMeets />} />
            <Route path='/UprmHomePage/Notifications' element={<Notifications />} />
            <Route path='/UprmHomePage/MeetsScheduled' element={<MeetsScheduled />} />
            <Route path='/UprmHomePage/MeetsPending' element={<MeetsPending />} />
          </Routes>

          <div id="lowerLine" className='thoseTwoLines'></div>
        </div>
      </Router>
    )
  }
}

export default connect(null, actions)(App);
