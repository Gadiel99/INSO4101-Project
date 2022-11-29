
import { FETCH_USER } from "../actions/types"

export default function (state = null, action) {
    console.log(action)
    switch (action.type) {
        case FETCH_USER:

            if (action.payload === '') {
                return false
            }
            return action.payload
        // return action.payload || false accomplishes the same
        default:
            return state;
    }
}