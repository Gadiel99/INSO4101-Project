import React from "react"
import { useNavigate } from "react-router-dom";


function About(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>About</h1>
            </div>
            <div id="aboutView"></div>
            <button onClick={() => { navigate("/") }}>Home Page</button>
        </>
    )
}
export default About;