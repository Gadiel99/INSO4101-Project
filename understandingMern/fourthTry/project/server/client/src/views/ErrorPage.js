import React from "react"
import { useNavigate } from "react-router-dom";


function ErrorPage(props) {
    let navigate = useNavigate();
    return (
        <>
            <div className="pageName">
                <h1>Error Page</h1>
            </div>
            <button onClick={() => { navigate("/") }}>Home Page</button>
        </>
    )
}
export default ErrorPage;