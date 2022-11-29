import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';


import { Provider } from 'react-redux';
import { createStore, applyMiddleware } from 'redux';

import reducers from './reducers'

import reduxThunk from 'redux-thunk'

const store = createStore(reducers, {}, applyMiddleware(reduxThunk))




const root = ReactDOM.createRoot(document.getElementById('root'));

root.render(

  <React.StrictMode>
    <Provider store={store}><App /></Provider>
  </React.StrictMode>
);

