import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function TimeSlots(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Time Slots</h1>
            </div>

            <NavBar />
            <button onClick={() => { navigate("/UprmHomePage/PairUp") }}>Pair Up</button>
            <div id="timeSlotsCalendar"></div>
        </>
    )
}
export default TimeSlots;