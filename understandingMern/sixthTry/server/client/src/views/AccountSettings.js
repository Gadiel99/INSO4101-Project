import React from "react"
import { useNavigate } from "react-router-dom";


function AccountSettings(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Account Settings</h1>
            </div>
            <button onClick={() => { navigate("/UprmHomePage/Account") }}>Account</button>
            <button>Confirm Changes</button>
            <div id="accountSettingsView"></div>
        </>
    )
}
export default AccountSettings;