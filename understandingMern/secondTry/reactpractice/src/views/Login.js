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
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>

        </>
    )
}
export default Login;