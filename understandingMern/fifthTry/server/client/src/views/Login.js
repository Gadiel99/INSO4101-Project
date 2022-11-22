import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function Login(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Login</h1>
            </div>
            <NavBar />
            <a href="http://localhost:5000/auth/google"> Sign in with google</a>
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>

        </>
    )
}
export default Login;