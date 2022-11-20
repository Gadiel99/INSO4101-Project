import React from "react"
import { useNavigate } from "react-router-dom";


function Account(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Account</h1>
            </div>
            <button onClick={() => { navigate("/UprmHomePage") }}>Uprm Home Page</button>
            <div id="accountInformation"></div>
            <button onClick={() => { navigate("/UprmHomePage/Account/AccountSettings") }}>Account Settings</button>
        </>
    )
}
export default Account;