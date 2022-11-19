import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function Match(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Match</h1>
            </div>
            <NavBar />
            <button onClick={() => { navigate("/UprmHomePage/PairUp") }}>Pair Up</button>
            <div id="otherCard"></div>
            <button>decline</button>
            <button>accept</button>
        </>
    )
}
export default Match;