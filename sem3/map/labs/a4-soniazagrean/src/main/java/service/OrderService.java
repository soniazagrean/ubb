package service;

import domain.Order;
import exceptions.ObjectNotFoundException;
import repository.IRepository;

import java.util.ArrayList;

public class OrderService {
    private final IRepository<Order> repo;

    public OrderService(IRepository<Order> repo) {
        this.repo = repo;
    }

    public void addOrder(Order o) {
        if (o.getDate() == null)
            throw new IllegalArgumentException("Order date cannot be empty");
        repo.addElement(o);
    }

    public Order getOrder(int id) {
        Order o = repo.findById(id);
        if (o == null)
            throw new ObjectNotFoundException(id);
        return o;
    }

    public void deleteOrder(int id) {
        repo.deleteElement(id);
    }

    public void updateOrder(Order o) {
        repo.updateElement(o);
    }

    public ArrayList<Order> getAllOrders() {
        return repo.getAll();
    }

    public int countOrders() {
        return repo.size();
    }

    public java.util.List<java.util.Map.Entry<String, Long>> getProductCountByCategory() {
        return repo.getAll().stream()
                .flatMap(o -> o.getProducts().stream())
                .collect(java.util.stream.Collectors.groupingBy(domain.Product::getCategory, java.util.stream.Collectors.counting()))
                .entrySet().stream()
                .sorted(java.util.Map.Entry.<String, Long>comparingByValue().reversed())
                .collect(java.util.stream.Collectors.toList());
    }

    public java.util.Map<java.time.Month, MonthStats> getMonthlyStats() {
        java.util.Map<java.time.Month, MonthStats> stats = new java.util.HashMap<>();
        repo.getAll().forEach(o -> {
            java.time.Month m = o.getDate().getMonth();
            stats.putIfAbsent(m, new MonthStats());
            MonthStats s = stats.get(m);
            s.orderCount++;
            s.totalRevenue += o.getProducts().stream().mapToInt(domain.Product::getPrice).sum();
        });
        return stats;
    }

    public static class MonthStats {
        public int orderCount = 0;
        public double totalRevenue = 0.0;
    }

    public java.util.List<java.util.Map.Entry<String, Integer>> getProductsByRevenue() {
        return repo.getAll().stream()
                .flatMap(o -> o.getProducts().stream())
                .collect(java.util.stream.Collectors.groupingBy(
                        domain.Product::getName,
                        java.util.stream.Collectors.summingInt(domain.Product::getPrice)
                ))
                .entrySet().stream()
                .sorted(java.util.Map.Entry.<String, Integer>comparingByValue().reversed())
                .collect(java.util.stream.Collectors.toList());
    }
}