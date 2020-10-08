// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/action/action.proto)

#include "action/action.grpc.pb.h"
#include "plugins/action/action.h"

#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace backend {

template<typename Action = Action>
class ActionServiceImpl final : public rpc::action::ActionService::Service {
public:
    ActionServiceImpl(Action& action) : _action(action) {}


    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::Action::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_action_result = new rpc::action::ActionResult();
        rpc_action_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_action_result->set_result_str(ss.str());

        response->set_allocated_action_result(rpc_action_result);
    }



    static rpc::action::ActionResult::Result translateToRpcResult(const mavsdk::Action::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::Action::Result::Unknown:
                return rpc::action::ActionResult_Result_RESULT_UNKNOWN;
            case mavsdk::Action::Result::Success:
                return rpc::action::ActionResult_Result_RESULT_SUCCESS;
            case mavsdk::Action::Result::NoSystem:
                return rpc::action::ActionResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::Action::Result::ConnectionError:
                return rpc::action::ActionResult_Result_RESULT_CONNECTION_ERROR;
            case mavsdk::Action::Result::Busy:
                return rpc::action::ActionResult_Result_RESULT_BUSY;
            case mavsdk::Action::Result::CommandDenied:
                return rpc::action::ActionResult_Result_RESULT_COMMAND_DENIED;
            case mavsdk::Action::Result::CommandDeniedLandedStateUnknown:
                return rpc::action::ActionResult_Result_RESULT_COMMAND_DENIED_LANDED_STATE_UNKNOWN;
            case mavsdk::Action::Result::CommandDeniedNotLanded:
                return rpc::action::ActionResult_Result_RESULT_COMMAND_DENIED_NOT_LANDED;
            case mavsdk::Action::Result::Timeout:
                return rpc::action::ActionResult_Result_RESULT_TIMEOUT;
            case mavsdk::Action::Result::VtolTransitionSupportUnknown:
                return rpc::action::ActionResult_Result_RESULT_VTOL_TRANSITION_SUPPORT_UNKNOWN;
            case mavsdk::Action::Result::NoVtolTransitionSupport:
                return rpc::action::ActionResult_Result_RESULT_NO_VTOL_TRANSITION_SUPPORT;
            case mavsdk::Action::Result::ParameterError:
                return rpc::action::ActionResult_Result_RESULT_PARAMETER_ERROR;
        }
    }

    static mavsdk::Action::Result translateFromRpcResult(const rpc::action::ActionResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::action::ActionResult_Result_RESULT_UNKNOWN:
                return mavsdk::Action::Result::Unknown;
            case rpc::action::ActionResult_Result_RESULT_SUCCESS:
                return mavsdk::Action::Result::Success;
            case rpc::action::ActionResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::Action::Result::NoSystem;
            case rpc::action::ActionResult_Result_RESULT_CONNECTION_ERROR:
                return mavsdk::Action::Result::ConnectionError;
            case rpc::action::ActionResult_Result_RESULT_BUSY:
                return mavsdk::Action::Result::Busy;
            case rpc::action::ActionResult_Result_RESULT_COMMAND_DENIED:
                return mavsdk::Action::Result::CommandDenied;
            case rpc::action::ActionResult_Result_RESULT_COMMAND_DENIED_LANDED_STATE_UNKNOWN:
                return mavsdk::Action::Result::CommandDeniedLandedStateUnknown;
            case rpc::action::ActionResult_Result_RESULT_COMMAND_DENIED_NOT_LANDED:
                return mavsdk::Action::Result::CommandDeniedNotLanded;
            case rpc::action::ActionResult_Result_RESULT_TIMEOUT:
                return mavsdk::Action::Result::Timeout;
            case rpc::action::ActionResult_Result_RESULT_VTOL_TRANSITION_SUPPORT_UNKNOWN:
                return mavsdk::Action::Result::VtolTransitionSupportUnknown;
            case rpc::action::ActionResult_Result_RESULT_NO_VTOL_TRANSITION_SUPPORT:
                return mavsdk::Action::Result::NoVtolTransitionSupport;
            case rpc::action::ActionResult_Result_RESULT_PARAMETER_ERROR:
                return mavsdk::Action::Result::ParameterError;
        }
    }




    grpc::Status Arm(
        grpc::ServerContext* /* context */,
        const rpc::action::ArmRequest* /* request */,
        rpc::action::ArmResponse* response) override
    {
        
        auto result = _action.arm();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Disarm(
        grpc::ServerContext* /* context */,
        const rpc::action::DisarmRequest* /* request */,
        rpc::action::DisarmResponse* response) override
    {
        
        auto result = _action.disarm();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Takeoff(
        grpc::ServerContext* /* context */,
        const rpc::action::TakeoffRequest* /* request */,
        rpc::action::TakeoffResponse* response) override
    {
        
        auto result = _action.takeoff();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Land(
        grpc::ServerContext* /* context */,
        const rpc::action::LandRequest* /* request */,
        rpc::action::LandResponse* response) override
    {
        
        auto result = _action.land();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Reboot(
        grpc::ServerContext* /* context */,
        const rpc::action::RebootRequest* /* request */,
        rpc::action::RebootResponse* response) override
    {
        
        auto result = _action.reboot();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Shutdown(
        grpc::ServerContext* /* context */,
        const rpc::action::ShutdownRequest* /* request */,
        rpc::action::ShutdownResponse* response) override
    {
        
        auto result = _action.shutdown();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Terminate(
        grpc::ServerContext* /* context */,
        const rpc::action::TerminateRequest* /* request */,
        rpc::action::TerminateResponse* response) override
    {
        
        auto result = _action.terminate();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status Kill(
        grpc::ServerContext* /* context */,
        const rpc::action::KillRequest* /* request */,
        rpc::action::KillResponse* response) override
    {
        
        auto result = _action.kill();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status ReturnToLaunch(
        grpc::ServerContext* /* context */,
        const rpc::action::ReturnToLaunchRequest* /* request */,
        rpc::action::ReturnToLaunchResponse* response) override
    {
        
        auto result = _action.return_to_launch();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status GotoLocation(
        grpc::ServerContext* /* context */,
        const rpc::action::GotoLocationRequest* request,
        rpc::action::GotoLocationResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "GotoLocation sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
            
        
            
        
            
        
        auto result = _action.goto_location(request->latitude_deg(), request->longitude_deg(), request->absolute_altitude_m(), request->yaw_deg());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status TransitionToFixedwing(
        grpc::ServerContext* /* context */,
        const rpc::action::TransitionToFixedwingRequest* /* request */,
        rpc::action::TransitionToFixedwingResponse* response) override
    {
        
        auto result = _action.transition_to_fixedwing();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status TransitionToMulticopter(
        grpc::ServerContext* /* context */,
        const rpc::action::TransitionToMulticopterRequest* /* request */,
        rpc::action::TransitionToMulticopterResponse* response) override
    {
        
        auto result = _action.transition_to_multicopter();
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status GetTakeoffAltitude(
        grpc::ServerContext* /* context */,
        const rpc::action::GetTakeoffAltitudeRequest* /* request */,
        rpc::action::GetTakeoffAltitudeResponse* response) override
    {
        

        auto result = _action.get_takeoff_altitude();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_altitude(result.second);
            
        }


        return grpc::Status::OK;
    }

    grpc::Status SetTakeoffAltitude(
        grpc::ServerContext* /* context */,
        const rpc::action::SetTakeoffAltitudeRequest* request,
        rpc::action::SetTakeoffAltitudeResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "SetTakeoffAltitude sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _action.set_takeoff_altitude(request->altitude());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status GetMaximumSpeed(
        grpc::ServerContext* /* context */,
        const rpc::action::GetMaximumSpeedRequest* /* request */,
        rpc::action::GetMaximumSpeedResponse* response) override
    {
        

        auto result = _action.get_maximum_speed();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_speed(result.second);
            
        }


        return grpc::Status::OK;
    }

    grpc::Status SetMaximumSpeed(
        grpc::ServerContext* /* context */,
        const rpc::action::SetMaximumSpeedRequest* request,
        rpc::action::SetMaximumSpeedResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "SetMaximumSpeed sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _action.set_maximum_speed(request->speed());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }

    grpc::Status GetReturnToLaunchAltitude(
        grpc::ServerContext* /* context */,
        const rpc::action::GetReturnToLaunchAltitudeRequest* /* request */,
        rpc::action::GetReturnToLaunchAltitudeResponse* response) override
    {
        

        auto result = _action.get_return_to_launch_altitude();

        if (response != nullptr) {
            fillResponseWithResult(response, result.first);
            
            response->set_relative_altitude_m(result.second);
            
        }


        return grpc::Status::OK;
    }

    grpc::Status SetReturnToLaunchAltitude(
        grpc::ServerContext* /* context */,
        const rpc::action::SetReturnToLaunchAltitudeRequest* request,
        rpc::action::SetReturnToLaunchAltitudeResponse* response) override
    {
        if (request == nullptr) {
            LogWarn() << "SetReturnToLaunchAltitude sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }
            
        
        auto result = _action.set_return_to_launch_altitude(request->relative_altitude_m());
        

        
        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }
        

        return grpc::Status::OK;
    }


    void stop() {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom) {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom) {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end(); /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    Action &_action;
    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises {};
};

} // namespace backend
} // namespace mavsdk