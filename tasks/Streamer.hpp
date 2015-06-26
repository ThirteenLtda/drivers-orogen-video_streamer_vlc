/* Generated from orogen/lib/orogen/templates/tasks/Streamer.hpp */

#ifndef VIDEO_STREAMER_VLC_STREAMER_TASK_HPP
#define VIDEO_STREAMER_VLC_STREAMER_TASK_HPP

#include "video_streamer_vlc/StreamerBase.hpp"
#include "opencv2/opencv.hpp"
#include "frame_helper/FrameHelper.h"
#include "video_streamer_vlc/VlcStream.hpp"


namespace video_streamer_vlc {

    /*! \class Streamer 
     * \brief The task context provides and requires services. It uses an ExecutionEngine to perform its functions.
     * Essential interfaces are operations, data flow ports and properties. These interfaces have been defined using the oroGen specification.
     * In order to modify the interfaces you should (re)use oroGen and rely on the associated workflow.
     * 
     * \details
     * The name of a StreamerContext is primarily defined via:
     \verbatim
     deployment 'deployment_name'
         task('custom_task_name','video_streamer_vlc::Streamer')
     end
     \endverbatim
     *  It can be dynamically adapted when the deployment is called with a prefix argument. 
     */

    struct PortHelper{
        RTT::InputPort< ::RTT::extras::ReadOnlyPointer< ::base::samples::frame::Frame > > *port;
        VlcStream *streamer;
        PortConfig config;
    };

    class Streamer : public StreamerBase
    {
	friend class StreamerBase;
    protected:
        RTT::extras::ReadOnlyPointer<base::samples::frame::Frame> current_image_;
        frame_helper::FrameHelper frame_helper;
        base::samples::frame::Frame rgb_image;

        virtual bool createInput(::video_streamer_vlc::PortConfig const & config);

        std::vector<PortHelper> my_ports;
    public:
        /** StreamerContext constructor for Streamer
         * \param name Name of the task. This name needs to be unique to make it identifiable via nameservices.
         * \param initial_state The initial StreamerState of the StreamerContext. Default is Stopped state.
         */
        Streamer(std::string const& name = "video_streamer_vlc::Streamer");

        /** StreamerContext constructor for Streamer 
         * \param name Name of the task. This name needs to be unique to make it identifiable for nameservices. 
         * \param engine The RTT Execution engine to be used for this task, which serialises the execution of all commands, programs, state machines and incoming events for a task. 
         * 
         */
        Streamer(std::string const& name, RTT::ExecutionEngine* engine);

        /** Default deconstructor of Streamer
         */
	~Streamer();

        /** This hook is called by Orocos when the state machine transitions
         * from PreOperational to Stopped. If it returns false, then the
         * component will stay in PreOperational. Otherwise, it goes into
         * Stopped.
         *
         * It is meaningful only if the #needs_configuration has been specified
         * in the task context definition with (for example):
         \verbatim
         task_context "StreamerName" do
           needs_configuration
           ...
         end
         \endverbatim
         */
        bool configureHook();

        /** This hook is called by Orocos when the state machine transitions
         * from Stopped to Running. If it returns false, then the component will
         * stay in Stopped. Otherwise, it goes into Running and updateHook()
         * will be called.
         */
        bool startHook();

        /** This hook is called by Orocos when the component is in the Running
         * state, at each activity step. Here, the activity gives the "ticks"
         * when the hook should be called.
         *
         * The error(), exception() and fatal() calls, when called in this hook,
         * allow to get into the associated RunTimeError, Exception and
         * FatalError states. 
         *
         * In the first case, updateHook() is still called, and recover() allows
         * you to go back into the Running state.  In the second case, the
         * errorHook() will be called instead of updateHook(). In Exception, the
         * component is stopped and recover() needs to be called before starting
         * it again. Finally, FatalError cannot be recovered.
         */
        void updateHook();

        /** This hook is called by Orocos when the component is in the
         * RunTimeError state, at each activity step. See the discussion in
         * updateHook() about triggering options.
         *
         * Call recover() to go back in the Runtime state.
         */
        void errorHook();

        /** This hook is called by Orocos when the state machine transitions
         * from Running to Stopped after stop() has been called.
         */
        void stopHook();

        /** This hook is called by Orocos when the state machine transitions
         * from Stopped to PreOperational, requiring the call to configureHook()
         * before calling start() again.
         */
        void cleanupHook();
    };
}

#endif

