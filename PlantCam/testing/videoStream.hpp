/**
 * Photogon Imaging System
 * Author: Jacob Harrison
 * Purpose: The videoStream class records frames from the camera and
 * sends them via UDP to source computer.
 */

#ifndef VIDEOSTREAM_HPP
#define VIDEOSTREAM_HPP

#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <thread>
#include <future>

class videoStream{
    private:
        int port;                /** the port number */
        std::string address;     /** the ip address of destination */   
        std::atomic<bool> halt;
        std::thread thread;

        /**
         * Stream
         * 
         * @param halt the boolean that determines if the streaming should
         *      continue.
         */
        void stream();

    public:

        /**
         * Creates a new videoStream object
         * 
         * @param address the ip address of the destination computer
         * @param port the port number of the destination copmuter that stream
         *      will be sent to
         */
        videoStream(const std::string& address, int port);

        ~videoStream();

        /**
         * Begin streaming to device
         * 
         * @param halt reference to boolean value determining when the streaming
         *      should cease.
         */
        void start();

        /**
         * Stop
         */
        void stop();

};

#endif