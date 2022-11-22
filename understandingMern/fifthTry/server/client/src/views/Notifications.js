import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function Notifications(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Notifications</h1>
            </div>
            <NavBar />
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>
            <div id="notificationsViewDiv"></div>
        </>
    )
}
export default Notifications;