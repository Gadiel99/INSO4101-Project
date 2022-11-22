import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function MeetsPending(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Meets Pending</h1>
            </div>
            <NavBar />
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>
            <div id="meetsPendingViewDiv"></div>
        </>
    )
}
export default MeetsPending;