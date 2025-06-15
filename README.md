# OOP_FINAL_PROJECT

 Kids-Carpooling-System
A system for managing kids' carpooling between parents and verified drivers. Enables ride scheduling, driver booking, and rating management.

Key Features:

>Parent-driver matching with availability tracking.

>Secure ride booking system.

>Post-ride rating and feedback.

>Real-time ride offer processing.

Working:

>The system connects parents needing rides for their children with verified drivers. Parents create ride offers with pickup/drop-off details, which are validated and stored in an active pool. A background process continuously matches these offers with available drivers based on location, timing, and preferences. When matched, drivers receive instant notifications and can accept rides through a secure booking system that prevents double-booking.

>The system automatically completes trips when the destination is reached and prompts parents to rate drivers. These ratings update driver reputation scores, which influence future matches.

Components Explanation:

>Parent: Creates ride offers and manages children's profiles.

>Driver: Books rides and sets availability schedules.

>CarpoolSystem: Core coordinator with three subsystems.

>Authentication: Verifies user types (Parent/Driver).

>Ride Matching: Processes offers against driver availability.

>Booking Management: Handles ride reservations and ratings.

Interesting Technical Challenges That We Might Face

> Parallel offers working at the same time

> Multiple drivers trying to book the same ride simultaneously.

> Matching multiple of offers with drivers efficiently.

> Some drivers receive too many offers, others too few.

> Expired offers consuming memory.
