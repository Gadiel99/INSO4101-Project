import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function MeetsScheduled(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Meets Scheduled</h1>
            </div>
            <NavBar />
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>
            <div id="meetsScheduledViewDiv"></div>
        </>
    )
}
export default MeetsScheduled;