import React from "react"
import { useNavigate } from "react-router-dom";
import NavBar from "../components/NavBar"

function EditMeets(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Edit Meets</h1>
            </div>
            <NavBar />
            <button onClick={() => { navigate("/UprmHomePage/PairUp") }}>Pair Up</button>
            <div id="editingMeetsView"></div>

        </>
    )
}
export default EditMeets;