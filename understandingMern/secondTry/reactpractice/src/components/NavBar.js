import React from "react"
import { useNavigate } from "react-router-dom";


function NavBar(props) {
    let navigate = useNavigate();
    return (
        <>
            <br />
            <div id="navBar">
                <button id="homeIcon
                " onClick={() => { navigate("/") }}>Home Page</button> <br />

                <button id="accountIcon" onClick={() => { navigate("/UprmHomePage/Account") }}>Account</button> <br />

                <button id="aboutIcon" onClick={() => { navigate("/About") }}>About</button><br />

                <button id="settingsIcon" onClick={() => { navigate("/UprmHomePage/Account/AccountSettings") }}>Settings</button>
            </div>
            <br />
        </>
    )
}
export default NavBar;