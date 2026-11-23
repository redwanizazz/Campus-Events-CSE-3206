#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/BookingEngine/BookingEngine.h"
#include "../src/Notification/IObserver.h"

// 1. Create the Mock Object to isolate the external dependency
class MockNotificationService : public IObserver {
public:
    MOCK_METHOD(void, update, (const std::string& message), (override));
};

// 2. Write the TDD Test
TEST(BookingTest, BookingTriggersNotification) {
    MockNotificationService mockService;
    BookingEngine engine;
    engine.addObserver(&mockService);

    // We expect the mock to receive the update function ONCE with a specific string
    EXPECT_CALL(mockService, update("Booking Confirmed: Event 101"))
        .Times(1);

    // Execute the action
    bool result = engine.bookTicket(1, 101); // User 1, Event 101
    EXPECT_TRUE(result);
}