import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function UprmHomePage(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Uprm Home Page</h1>
            </div>
            <NavBar />

            <div height="20%" width="" id="UniversityDiv"></div>
            <div id="EnrollmentSwitchDiv"></div>
            <div className="UHPbuttonsDiv">


                <button onClick={() => { navigate("/UprmHomePage/Notifications") }}>Notifications</button>

                <button onClick={() => { navigate("/UprmHomePage/MeetsScheduled") }}>Meets Scheduled</button>

                <button onClick={() => { navigate("/UprmHomePage/MeetsPending") }}>Meets Pending</button> <br />
                <button onClick={() => { navigate("/UprmHomePage/PairUp") }}>Pair Up</button>

            </div>
            <br />
            <br />

        </>
    )
}
export default UprmHomePage;