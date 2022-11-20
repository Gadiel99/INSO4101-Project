import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function PairUp(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Pair Up</h1>
            </div>
            <NavBar />
            <div class="UHPbuttonsDiv">
                <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>
                <br />
                <div id="hardViewDiv"></div>

                <button onClick={() => { navigate("/UprmHomePage/PairUp/TimeSlots") }}>Time Slots</button>
                <button onClick={() => { navigate("/UprmHomePage/PairUp/EditMeets") }}>Edit Meets</button>

                <br />
                <button onClick={() => { navigate("/UprmHomePage/PairUp/Match") }}>Match</button>
            </div>
        </>
    )
}
export default PairUp;