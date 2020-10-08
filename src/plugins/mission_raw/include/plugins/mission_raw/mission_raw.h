// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/mission_raw/mission_raw.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "plugin_base.h"

namespace mavsdk {

class System;
class MissionRawImpl;

/**
 * @brief Enable raw missions as exposed by MAVLink.
 */
class MissionRaw : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto mission_raw = std::make_shared<MissionRaw>(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit MissionRaw(System& system);

    /**
     * @brief Destructor (internal use only).
     */
    ~MissionRaw();





    /**
     * @brief Mission progress type.
     */
    struct MissionProgress {
        
        int32_t current{}; /**< @brief Current mission item index (0-based) */
        int32_t total{}; /**< @brief Total number of mission items */
    };

    /**
     * @brief Equal operator to compare two `MissionRaw::MissionProgress` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const MissionRaw::MissionProgress& lhs, const MissionRaw::MissionProgress& rhs);

    /**
     * @brief Stream operator to print information about a `MissionRaw::MissionProgress`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, MissionRaw::MissionProgress const& mission_progress);




    /**
     * @brief Mission item exactly identical to MAVLink MISSION_ITEM_INT.
     */
    struct MissionItem {
        
        uint32_t seq{}; /**< @brief Sequence (uint16_t) */
        uint32_t frame{}; /**< @brief The coordinate system of the waypoint (actually uint8_t) */
        uint32_t command{}; /**< @brief The scheduled action for the waypoint (actually uint16_t) */
        uint32_t current{}; /**< @brief false:0, true:1 (actually uint8_t) */
        uint32_t autocontinue{}; /**< @brief Autocontinue to next waypoint (actually uint8_t) */
        float param1{}; /**< @brief PARAM1, see MAV_CMD enum */
        float param2{}; /**< @brief PARAM2, see MAV_CMD enum */
        float param3{}; /**< @brief PARAM3, see MAV_CMD enum */
        float param4{}; /**< @brief PARAM4, see MAV_CMD enum */
        int32_t x{}; /**< @brief PARAM5 / local: x position in meters * 1e4, global: latitude in degrees * 10^7 */
        int32_t y{}; /**< @brief PARAM6 / y position: local: x position in meters * 1e4, global: longitude in degrees *10^7 */
        float z{}; /**< @brief PARAM7 / local: Z coordinate, global: altitude (relative or absolute, depending on frame) */
        uint32_t mission_type{}; /**< @brief @brief Mission type (actually uint8_t) */
    };

    /**
     * @brief Equal operator to compare two `MissionRaw::MissionItem` objects.
     *
     * @return `true` if items are equal.
     */
    friend bool operator==(const MissionRaw::MissionItem& lhs, const MissionRaw::MissionItem& rhs);

    /**
     * @brief Stream operator to print information about a `MissionRaw::MissionItem`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, MissionRaw::MissionItem const& mission_item);





    /**
     * @brief Possible results returned for action requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request succeeded. */
        Error, /**< @brief Error. */
        TooManyMissionItems, /**< @brief Too many mission items in the mission. */
        Busy, /**< @brief Vehicle is busy. */
        Timeout, /**< @brief Request timed out. */
        InvalidArgument, /**< @brief Invalid argument. */
        Unsupported, /**< @brief Mission downloaded from the system is not supported. */
        NoMissionAvailable, /**< @brief No mission available on the system. */
        TransferCancelled, /**< @brief Mission transfer (upload or download) has been cancelled. */
    };

    /**
     * @brief Stream operator to print information about a `MissionRaw::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, MissionRaw::Result const& result);



    /**
     * @brief Callback type for asynchronous MissionRaw calls.
     */
    using ResultCallback = std::function<void(Result)>;




    /**
     * @brief Upload a list of raw mission items to the system.
     *
     * The raw mission items are uploaded to a drone. Once uploaded the mission
     * can be started and executed even if the connection is lost.
     *
     * This function is non-blocking. See 'upload_mission' for the blocking counterpart.
     */
    void upload_mission_async(std::vector<MissionItem> mission_items, const ResultCallback callback);



    /**
     * @brief Upload a list of raw mission items to the system.
     *
     * The raw mission items are uploaded to a drone. Once uploaded the mission
     * can be started and executed even if the connection is lost.
     *
     * This function is blocking. See 'upload_mission_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result upload_mission(std::vector<MissionItem> mission_items) const;






    /**
     * @brief Cancel an ongoing mission upload.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result cancel_mission_upload() const;




    /**
    * @brief Callback type for download_mission_async.
    */
    using DownloadMissionCallback = std::function<void(Result, std::vector<MissionItem>)>;

    /**
     * @brief Download a list of raw mission items from the system (asynchronous).
     *
     * This function is non-blocking. See 'download_mission' for the blocking counterpart.
     */
    void download_mission_async(const DownloadMissionCallback callback);



    /**
     * @brief Download a list of raw mission items from the system (asynchronous).
     *
     * This function is blocking. See 'download_mission_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    std::pair<Result, std::vector<MissionRaw::MissionItem>> download_mission() const;






    /**
     * @brief Cancel an ongoing mission download.
     *
     * This function is blocking.
     *
     * @return Result of request.
     */
    Result cancel_mission_download() const;




    /**
     * @brief Start the mission.
     *
     * A mission must be uploaded to the vehicle before this can be called.
     *
     * This function is non-blocking. See 'start_mission' for the blocking counterpart.
     */
    void start_mission_async(const ResultCallback callback);



    /**
     * @brief Start the mission.
     *
     * A mission must be uploaded to the vehicle before this can be called.
     *
     * This function is blocking. See 'start_mission_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result start_mission() const;




    /**
     * @brief Pause the mission.
     *
     * Pausing the mission puts the vehicle into
     * [HOLD mode](https://docs.px4.io/en/flight_modes/hold.html).
     * A multicopter should just hover at the spot while a fixedwing vehicle should loiter
     * around the location where it paused.
     *
     * This function is non-blocking. See 'pause_mission' for the blocking counterpart.
     */
    void pause_mission_async(const ResultCallback callback);



    /**
     * @brief Pause the mission.
     *
     * Pausing the mission puts the vehicle into
     * [HOLD mode](https://docs.px4.io/en/flight_modes/hold.html).
     * A multicopter should just hover at the spot while a fixedwing vehicle should loiter
     * around the location where it paused.
     *
     * This function is blocking. See 'pause_mission_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result pause_mission() const;




    /**
     * @brief Clear the mission saved on the vehicle.
     *
     * This function is non-blocking. See 'clear_mission' for the blocking counterpart.
     */
    void clear_mission_async(const ResultCallback callback);



    /**
     * @brief Clear the mission saved on the vehicle.
     *
     * This function is blocking. See 'clear_mission_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result clear_mission() const;




    /**
     * @brief Sets the raw mission item index to go to.
     *
     * By setting the current index to 0, the mission is restarted from the beginning. If it is set
     * to a specific index of a raw mission item, the mission will be set to this item.
     *
     * This function is non-blocking. See 'set_current_mission_item' for the blocking counterpart.
     */
    void set_current_mission_item_async(int32_t index, const ResultCallback callback);



    /**
     * @brief Sets the raw mission item index to go to.
     *
     * By setting the current index to 0, the mission is restarted from the beginning. If it is set
     * to a specific index of a raw mission item, the mission will be set to this item.
     *
     * This function is blocking. See 'set_current_mission_item_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result set_current_mission_item(int32_t index) const;




        
    /**
    * @brief Callback type for subscribe_mission_progress.
    */
        
    using MissionProgressCallback = std::function<void(MissionProgress)>;

    /**
     * @brief Subscribe to mission progress updates.
     */
    void subscribe_mission_progress(MissionProgressCallback callback);



    /**
     * @brief Poll for 'MissionProgress' (blocking).
     *
     * @return One MissionProgress update.
     */
    MissionProgress mission_progress() const;




        
    /**
    * @brief Callback type for subscribe_mission_changed.
    */
        
    using MissionChangedCallback = std::function<void(bool)>;

    /**
     * @brief *
     * Subscribes to mission changed.
     *
     * This notification can be used to be informed if a ground station has
     * been uploaded or changed by a ground station or companion computer.
     *
     * @param callback Callback to notify about change.
     */
    void subscribe_mission_changed(MissionChangedCallback callback);






    /**
     * @brief Copy constructor (object is not copyable).
     */
    MissionRaw(const MissionRaw&) = delete;

    /**
     * @brief Equality operator (object is not copyable).
     */
    const MissionRaw& operator=(const MissionRaw&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<MissionRawImpl> _impl;
};

} // namespace mavsdk