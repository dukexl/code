#include <iostream>

#include "pulsar/Client.h"
#include "pulsar/Producer.h"
#include "pulsar/ProducerConfiguration.h"

using pulsar::Client;
using pulsar::Consumer;
using pulsar::ConsumerConfiguration;
using pulsar::Message;
using pulsar::MessageBuilder;
using pulsar::Producer;
using pulsar::ProducerConfiguration;
using pulsar::Result;

int main()
{
    { // 生产者

        Client client("pulsar://172.18.252.252:6650");

        Producer producer;
        Result result = client.createProducer("my-topic", producer);
        if (result != Result::ResultOk)
        {
            std::cout << "Error creating producer" << std::endl;
            return -1;
        }

        // Publish 10 messages to the topic
        for (int i = 0; i < 10; i++)
        {
            Message msg = MessageBuilder().setContent("my-message").build();
            Result res = producer.send(msg);
            // LOG_INFO("Message sent: " << res);
            if (res != Result::ResultOk)
            {
                std::cout << "Error  producer send " << std::endl;
                return -1;
            }
            std::cout << "Message sent" << std::endl;
        }
        client.close();
    }

    { // 消费者

        Client client("pulsar://172.18.252.252:6650");
        Consumer consumer;
        Result result = client.subscribe("my-topic", "my-subscription-name", consumer);
        if (result != Result::ResultOk)
        {
            // LOG_ERROR("Failed to subscribe: " << result);
            std::cout << "Error creating producer" << std::endl;

            return -1;
        }

        Message msg;

        while (true)
        {
            consumer.receive(msg);
            // LOG_INFO("Received: " << msg
            //                       << "  with payload '" << msg.getDataAsString() << "'");
            std::cout << "Received:" << msg.getDataAsString() << std::endl;

            consumer.acknowledge(msg);
        }

        client.close();
    }

    return 0;
}
