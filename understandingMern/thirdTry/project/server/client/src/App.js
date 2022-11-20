
import './App.css';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom'

const Header = () => <h2>header</h2>
const Dashboard = () => <h2>Dashboard</h2>
const Landing = () => <h2>Landing</h2>

function App() {
  return (
    <div className="App">
      <a href="http://localhost:5000/auth/google"> Sign in with google</a>

      <>
        <Router>
          <Routes>
            <>
              <Route path='/' element={<Landing />} />
              <Route path='/surveys' element={<Dashboard />} />
            </>
          </Routes>
        </Router>
      </>

    </div>
  );
}

export default App;
