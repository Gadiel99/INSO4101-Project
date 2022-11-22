import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function HomePage(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Home Page</h1>
            </div>
            <NavBar />

            <button onClick={() => { navigate("/Login") }}>Login</button>
            <br /><br />
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>
        </>
    )
}
export default HomePage;